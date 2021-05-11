
"""Write a python program to store second year percentage of students in array.
Write function for sorting array of floating-point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores """


class Sort:
	def __init__(self):
		self.arr = []
		self.size = 0

	def get(self):
		# taking input for the self.size of the array
		self.size = int(input("Enter size: "))
		print("Enter percentage of students: ")
		for i in range(self.size):							# taking input for the array elements
			score = float(input())
			self.arr.append(score)

	def display(self, l):
		# printing the top 5 scores from the array
		print("The top five scores are: ")
		n = 5
		result = l[-n:]
		print(result)

	# function to perform insertion sort
	def insertion_sort(self):
		list = self.arr
		for i in range(1, self.size):						# traversing from through the array
			temp = list[i]
			j = i - 1
			# comparing the (i)th element with next (j)th element
			while(j >= 0 and temp < list[j]):
				list[j+1] = list[j]			# swaping if (j)th element is smaller
				j -= 1
				list[j+1] = temp							# assinging the next temp vlaue
		return list

	# function to perform shell sort
	def shell_sort(self):
		list = self.arr  
		interval = self.size // 2				# creating an interval by dividing the array
		while (interval > 0):
			for i in range(interval, self.size):  # comparing the elements at the step of the interval
				temp = list[i]
				j = i
				while(j >= interval and list[j - interval] > temp):
					list[j] = list[j - interval]				# swaping if element is smaller
					j -= interval
					list[j] = temp							# assigning the next temp value
			interval //= 2			# further dividing the interval by 2 making it smaller
		return list

	def get_len(self):
		return self.size


s = Sort()		 								# creating a class object
s.get()
choice = "y"
while choice == "y":
	print("\nMENU")
	print("\n1. insertion sort\n2.   shell sort")
	ch = int(input("Enter your choice(1/2): "))
	print("\n")
	
	# choice to perform insertion sort	
	if ch == 1:
		l=s.insertion_sort()
		s.display(l)
	
	# choice to perform shell sort	
	elif ch == 2:
		l=s.shell_sort()
		s.display(l)
		
	else:
		print("Wrong Choice.")
	
	choice = input("\nDo you wish to continue(y/n): ")
	
print("\nEnd")
