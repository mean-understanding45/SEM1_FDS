
"""a) Write a python program to store roll numbers of student in array who attended training program in random order.
 Write function for searching whether particular student attended training program or not, 
 using Linear search and Sentinel search. 
 b) Write a python program to store roll numbers of student array who attended training program in sorted order. 
 Write function for searching whether particular student attended training program or not,
  using Binary search and Fibonacci search """

class search:
    def __init__(self):
        self.rollno=[]
        self.count=0

    def input(self):
        self.count=int(input("Enter Number of Students : "))
        print('Enter Roll.No of students: ')
        for i in range(self.count):
            x=int(input())
            self.rollno.append([x,i])

    def liner_search(self):
        m=int(input("Roll no to search : "))
        ans=None
        for i in range(self.count):
            if(self.rollno[i][0]==m):
                ans=i
                break
            
        if(ans!=None):
            return ans
        else:
            return -1

    def sentinel_search(self):
        m=int(input("Roll no to search : "))
        l=self.rollno[self.count-1][0]
        self.rollno[self.count-1][0]=m
        ans=0
        while(self.rollno[ans][0]!=m):
            ans=ans+1        
        self.rollno[self.count-1][0]=l      
        if(ans!=self.count-1 or m==l):
            return ans
        else:
            return [-1,0]
    
    def selection_sort(self,list):
        n=len(list)
        for i in range(n):
            j=i
            for k in range(i+1,n):
                if (list[k][0]<list[i][0]):
                    j=k
                    t=list[i]
                    list[i]=list[j]
                    list[j]=t
        return list

    def binary_search(self):
        lst=self.selection_sort(self.rollno) 
        x=int(input("Roll no to search : "))
        l=0
        r=self.count-1
        while(l<=r):
            m=(l+r)//2
            if(x<lst[m][0]):
                r=m-1
            elif(x>lst[m][0]):
                l=m+1
            else:
                return lst[m]
            
        else:
            return [-1,0]

    def fib_search(self):
        x=int(input("Roll no to search : "))
        l=self.selection_sort(self.rollno)
        offset=-1
        fibm1=0
        fibm2=1
        fibm=fibm1+fibm2

        while(fibm<self.count):
            fibm2=fibm1
            fibm1=fibm
            fibm=fibm2+fibm1

        while(fibm>1):
            i=min(offset+fibm2,self.count-1)
            if (l[i][0]<x):
                fibm=fibm1
                fibm1=fibm2
                fibm2=fibm-fibm1
                offset=l[i][0]
            elif(l[i][0]>x):
                fibm=fibm2
                fibm1-=fibm2
                fibm2=fibm-fibm1
            else:
                return l[i][1]

        if (fibm1 and l[offset+1][0]==x):
            return offset+1
        return -1
    

a=search()
a.input()
while(1):
    print("-------------------------------------------------------------")
    print("1.Linear Search")
    print("2.Binary Search")
    print("3.Fib search")
    print("4.Sentinal Search")
    print("Enter Your Choice : ")
    ch = int(input())
    if ch==1:
        s=a.liner_search()
        if (s!=-1):
            print("Present at index",s)
        else:
            print("Absent")
    elif ch==2:
        s=a.binary_search()
        if (s[0]!=-1):
            print("Present at index",s[1])
        else:
            print("Absent")
    elif ch==3:
        s=a.fib_search()
        if (s!=-1):
            print("Present at index",s)
        else:
            print("Absent")
    elif ch==4:
        s=a.sentinel_search()
        if (s!=-1):
            print("Present at index",s)
        else:
            print("Absent")