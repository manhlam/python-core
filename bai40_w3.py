#Write a Python program to compute the distance between the points (x1, y1) and (x2, y2)

import math
p1 = [1, 5]
p2 = [-4, 2]
distance = math.sqrt((p2[0] - p1[0]) ** 2 + (p2[1] - p1[1]) ** 2)
print(round(distance, 2))