"""Write a python program to store first year percentage of students in array.
Write function for sorting array of floating point numbers in ascending order using quick sort and display
top five scores."""

class Sort:
    def __init__(self):
        self.l=[]
        self.len = 0

    def create_list(self):
        n = int(input("Enter The Total Number of Students :"))
        while n < 0:
            print("Invalid data. Please re-enter")
            n = int(input("Enter The Total Number of Students :"))
        for i in range(n):
            x = float(input("Enter percentage"))
            while x < 0 or x > 100:
                print("Invalid values for percentage. Please re-enter")
                x = float(input("Enter percentage"))
            self.l.append(x)
            self.len += 1
        return self.l

    def length(self):
        return self.len

    def quick_sort(self, a, l, h):
        if l < h:
            pivot = self.partition(a, l, h)
            self.quick_sort(a, l, pivot - 1)
            self.quick_sort(a, pivot + 1, h)
        return a

    def partition(self,array,low,high):
        i=low-1
        pivot=array[high]
        for j in range(low,high):
            if array[j]<pivot:
                i+=1
                array[i],array[j]=array[j],array[i]
        array[i+1],array[high]=array[high],array[i+1]
        return i+1

while True:
    print("_______________________________________________________________")
    print("Enter Your Choice: ")
    print("1.Create List of Percentages")
    print("2.Get top 5 percentages by quick sort algorithm")
    print("3.Exit")
    ch=int(input())
    if ch==1:
        print("_______________________________________________________________")
        s = Sort()
        x=s.create_list()
    elif ch==2:
        n=s.length()
        st=0
        h=n-1
        l=s.quick_sort(x,st,h)
        rank = 1
        i = 1
        while i <= n and rank <= 5:
            print("rank", rank, "percentage", l[-i])
            a = l[-i]
            l[-i] = -100
            ans = True
            if a in l:
                ans = False
            if ans:
                rank += 1
            i += 1

    elif ch==3:
        print("_______________________________________________________________")
        print("Thank You!")
        break
    else:
        print("Enter Valid Choice")