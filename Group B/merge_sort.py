def merge_sort(a):
    if len(a) > 1:
        mid = len(a) // 2
        left = a[:mid]
        right = a[mid:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                a[k] = left[i]
                i += 1
            else:
                a[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            a[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            a[k] = right[j]
            j += 1
            k += 1


n = int(input("Enter number of orders: "))
orders = []

for i in range(n):
    time = int(input("Enter delivery time in minutes: "))
    orders.append(time)

print("Before Sorting:", orders)
merge_sort(orders)
print("Orders sorted by delivery time:", orders)
