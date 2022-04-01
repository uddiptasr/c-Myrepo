Create a class which helps determine a family tree for a person.
 It should have 2 methods: 
Get the family tree starting from the person.
Get the family tree till the person i.e., 
from the first member to the person.
For example, 
A is a parent of C
B is a parent of C
A is a parent of D
B is a parent of D
Z is a parent of A

 
 c: a b 
 d: a b
 a: z
 a-> d c
 z-- a, c ,d   
 		func(c) func(d)



 		def children(geanology,person):
 			status=0
 			result=[]
 			for i in geanology.key()
 				if person in geanology[i]
 					status=1
 			if(status==0)
 				return []

 			for i in geanology.key()
 				if person in geanology[i]
 					result+=children(geanology,i) + [i]
 			return result

 		def ancestors(geanology,person):
			if person in geanology:
				parents=geanology[person]
				result=parents
				for i in parents:
					result=result+ ancestors(geanology,i)
				return result
			return []


 		main function
 		geanology={
 			 'c':['a','b']
 			 'd':['a','b']
 			 'a':['z']
 		}
 		for i in range(len(geanology))
 			person=list(geanology.keys())[i]
 			children(geanology,person)
 			ancestor(geanology,person)

 		O(numberOfkeys)
 	 person1= parent[] , children[]
