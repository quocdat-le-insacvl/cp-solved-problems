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
    if os.path.splitext(f)[1] in [".cpp", ".py"]
]

with open("README.md", "w") as f:
    # Title
    title = f"**{len(result)}** problems have been solved for all time!\n"
    f.write(title)
    f.write("=" * len(title) + "\n")

    # Heatmap
    f.write("![](heatmap.png)\n")

    # Print problems
    # for index, problem in enumerate(result):
        # f.write(str(index + 1) + ". " + problem + "\n")

# Init
# dates = date_range("2023-01-01", "2023-12-31")
dates = date_range("2024-01-01", "2024-01-31")
d = defaultdict(int)
for date in dates:
    d[date] = 0

# get files's date creation
date_files = [
    datetime.utcfromtimestamp(os.path.getmtime(path)).strftime("%Y-%m-%d")
    for path in result
]
date_files = [datetime.strptime(date, "%Y-%m-%d").date() for date in date_files]

# Add solved exercises which are corresponding to each creation date
for date in date_files:
    d[date] += 1

for date in d:
    if str(date) in ["2023-10-11","2023-10-07"] :
        d[date] = 5
    # 2023-10-7 : 45
    if d[date] != 0:
        print(f"{date} : {d[date]}")
        
# get month not zero
months = []
for date in d:
    if d[date] != 0:
        if date.month not in months:
            months.append(date.month)

# Export to list, then give it to july.heatmap
dates_list, data = [], []
for date in d:
    dates_list.append(date)
    data.append(d[date])

# Plot & save
# july.heatmap(dates_list, data, title="Activity", cmap="github", colorbar=True)
import matplotlib.pyplot as plt
from pylab import *
# months.append(11)
# months.append(11)
months.append(1)

# subplots_adjust(hspace=0.400)
# subplots_adjust(wspace=1.900)
number_of_subplots=len(months)

from mpl_toolkits.axes_grid1 import Grid
fig = plt.figure()
grid = Grid(fig, rect=111, nrows_ncols=(1,2),
            axes_pad=0.25, label_mode='L',
            )
for i, ax in enumerate(grid):
    july.month_plot(dates_list, data, month=months[i], value_label=True, ax=ax)


plt.tight_layout()

plt.savefig("heatmap.png")
