time_24 = input("Enter the time: ").split(':')
hours_24 = int(time_24[0])
hours_12 = 0
if hours_24 >12:
    hours_12 = hours_24 - 12
    fun = "PM"
elif hours_24 in  range(0,13):
    hours_12 = hours_24
    fun = "AM"
hours_12_str = str(hours_12)
print(f"{hours_12_str}:{time_24[1]}:{time_24[2]} {fun}")