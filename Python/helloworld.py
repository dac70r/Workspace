import tkinter as tk
from datetime import datetime
 
# Getting Datetime from timestamp
date_time = datetime.fromtimestamp(1887639468)
print("Datetime from timestamp:", date_time)

# 
window = tk.Tk()
greeting = tk.Label(text="Hello, Tkinter")
greeting.pack()

print("hello world")

input()
