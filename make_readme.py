import os
from datetime import datetime
from collections import defaultdict

import numpy as np
import matplotlib.pyplot as plt
import july
from july.utils import date_range


PATH = "./"
result = [
    os.path.join(dp, f)
    for dp, dn, filenames in os.walk(PATH)
    for f in filenames
    if os.path.splitext(f)[1] == ".cpp"
]

with open("README.md", "w") as f:
    # Title
    title = f"**{len(result)}** problems are solved for all time!\n"
    f.write(title)
    f.write("=" * len(title) + "\n")

    # Heatmap
    f.write("![](heatmap.png)\n")

    # Print problems
    for index, problem in enumerate(result):
        f.write(str(index + 1) + ". " + problem + "\n")

# Init
dates = date_range("2022-01-01", "2022-12-31")
d = defaultdict(int)
for date in dates:
    d[date] = 0

# get files's date creation
date_files = [
    datetime.utcfromtimestamp(os.path.getctime(path)).strftime("%Y-%m-%d")
    for path in result
]
date_files = [datetime.strptime(date, "%Y-%m-%d").date() for date in date_files]

# Add solved exercises which are corresponding to each creation date
for date in date_files:
    d[date] += 1

# Export to list, then give it to july.heatmap
dates_list, data = [], []
for date in d:
    dates_list.append(date)
    data.append(d[date])

# Plot & save
july.heatmap(dates_list, data, title="Github Activity", cmap="github", colorbar=True)
plt.savefig("heatmap.png")
