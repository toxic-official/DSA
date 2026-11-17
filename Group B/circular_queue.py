size = 5
q = [0] * size
front = -1
rear = -1

def enqueue(x):
    global front, rear

    if (rear + 1) % size == front:
        print("Queue is Full")
    else:
        if front == -1:
            front = 0

        rear = (rear + 1) % size
        q[rear] = x
        print("Inserted:", x)


def dequeue():
    global front, rear

    if front == -1:
        print("Queue is Empty")
    else:
        print("Deleted:", q[front])

        if front == rear:
            front = rear = -1
        else:
            front = (front + 1) % size


def display():
    if front == -1:
        print("Queue is Empty")
    else:
        i = front

        while True:
            print(q[i], end=" ")

            if i == rear:
                break

            i = (i + 1) % size

        print()


while True:
    print("\n1. Enqueue")
    print("2. Dequeue")
    print("3. Display")
    print("4. Exit")

    ch = int(input("Enter choice: "))

    if ch == 1:
        x = int(input("Enter value: "))
        enqueue(x)
    elif ch == 2:
        dequeue()
    elif ch == 3:
        display()
    elif ch == 4:
        break
    else:
        print("Invalid Choice")
