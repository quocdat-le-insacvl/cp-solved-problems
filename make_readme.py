import enum
import os

PATH = "./"
result = [
    os.path.join(dp, f)
    for dp, dn, filenames in os.walk(PATH)
    for f in filenames
    if os.path.splitext(f)[1] == ".cpp"
]

with open("README.md", "w") as f:
    title = f"**{len(result)}** problems are solved for all time!\n"
    f.write(title)
    f.write("=" * len(title) + "\n")
    for index, problem in enumerate(result):
        f.write(str(index + 1) + ". " + problem + "\n")
