import os
import re
import html
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"

START = "<!-- LEETCODE-START -->"
END = "<!-- LEETCODE-END -->"

LANGUAGES = {
    ".py": "Python",
    ".c": "C",
    ".cpp": "C++",
    ".java": "Java",
    ".js": "JavaScript",
    ".ts": "TypeScript",
    ".go": "Go",
    ".rs": "Rust",
    ".cs": "C#",
    ".sql": "SQL",
}


def get_problem(folder):
    problem_readme = folder / "README.md"

    if not problem_readme.exists():
        return None

    content = problem_readme.read_text(encoding="utf-8")

    # Extract problem title
    title_match = re.search(
        r'<h2>\s*<a[^>]*>(.*?)</a>\s*</h2>',
        content,
        re.IGNORECASE | re.DOTALL
    )

    # Extract difficulty
    difficulty_match = re.search(
        r'<h3>\s*(Easy|Medium|Hard)\s*</h3>',
        content,
        re.IGNORECASE
    )

    if not title_match or not difficulty_match:
        return None

    title = html.unescape(re.sub(r"<[^>]+>", "", title_match.group(1))).strip()

    title = re.sub(r"^\d+\.\s*", "", title)

    difficulty = difficulty_match.group(1).capitalize()

    # Find solution file
    solution_files = [
        file for file in folder.iterdir()
        if file.is_file()
        and file.suffix.lower() in LANGUAGES
    ]

    if not solution_files:
        return None

    solution = sorted(solution_files)[0]

    number_match = re.match(r"(\d+)-", folder.name)

    if not number_match:
        return None

    number = int(number_match.group(1))

    relative_solution = solution.relative_to(ROOT).as_posix()
    relative_readme = problem_readme.relative_to(ROOT).as_posix()

    return {
        "number": number,
        "title": title,
        "difficulty": difficulty,
        "language": LANGUAGES[solution.suffix.lower()],
        "readme": relative_readme,
        "solution": relative_solution,
    }


def generate_table():
    problems = []

    for folder in ROOT.iterdir():

        if not folder.is_dir():
            continue

        if not re.match(r"^\d{4}-", folder.name):
            continue

        problem = get_problem(folder)

        if problem:
            problems.append(problem)

    problems.sort(key=lambda p: p["number"])

    rows = [
        "| # | Problem | Difficulty | Language | Solution |",
        "|---|---|---|---|---|"
    ]

    for p in problems:
        rows.append(
            f"| {p['number']} "
            f"| [{p['title']}]({p['readme']}) "
            f"| {p['difficulty']} "
            f"| {p['language']} "
            f"| [View]({p['solution']}) |"
        )

    return "\n".join(rows)


def update_readme():
    content = README.read_text(encoding="utf-8")

    if START not in content or END not in content:
        raise ValueError("README markers not found!")

    start = content.index(START) + len(START)
    end = content.index(END)

    table = "\n" + generate_table() + "\n"

    updated = content[:start] + table + content[end:]

    README.write_text(updated, encoding="utf-8")

    print("README updated successfully!")


if __name__ == "__main__":
    update_readme()
