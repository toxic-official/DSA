n = int(input("Enter number of parcels: "))
weight = []
profit = []

for i in range(n):
    w = int(input("Enter parcel weight: "))
    p = int(input("Enter parcel profit: "))
    weight.append(w)
    profit.append(p)

capacity = int(input("Enter truck capacity: "))
ratio = []

for i in range(n):
    ratio.append(profit[i] / weight[i])

total = 0

for i in range(n):
    for j in range(i + 1, n):
        if ratio[i] < ratio[j]:
            ratio[i], ratio[j] = ratio[j], ratio[i]
            weight[i], weight[j] = weight[j], weight[i]
            profit[i], profit[j] = profit[j], profit[i]

for i in range(n):
    if capacity >= weight[i]:
        total += profit[i]
        capacity -= weight[i]
    else:
        total += ratio[i] * capacity
        capacity = 0
        break

print("Maximum Profit:", total)
