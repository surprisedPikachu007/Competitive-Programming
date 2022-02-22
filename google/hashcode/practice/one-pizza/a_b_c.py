import itertools

with open('inputs/c_coarse.in.txt', 'r') as file:
    data = file.read().split('\n')

n = int(data[0])
n=n*2

i=0
ingredients = []

while i<n:
    dat = data[i+1].split(' ')
    for j in dat:
        ingredients.append(j)
    i+=1

ingredients_names = [x for x in ingredients if not (x.isdigit() or x=='-' and x[1:].isdigit())]

ingredients_names = list(set(ingredients_names))

count = len(ingredients_names)
combination = pow(2,count)-1

p=int(n/2)
d={}

value = []
liked = []
disliked = []

i=1
j=0
while i<=n:
    liked = data[i].split(' ') 
    liked = [x for x in liked if not (x.isdigit() or x=='-' and x[1:].isdigit())]
    disliked = data[i+1].split(' ')
    disliked = [x for x in disliked if not (x.isdigit() or x=='-' and x[1:].isdigit())]
    value=[]
    value.append(liked)
    value.append(disliked)
    d.update({j: value})
    i+=2
    j+=1
    
def boughtno():
    bought = []
    for i in range(int(p)):
        flag = 0
        for x in d[i][0]:
            if(x not in final_list):
                flag = 1

        for y in d[i][1]:
            if(y in final_list):
                flag = 1

        if(flag==0):
            bought.append(i)
            
    return len(bought)

maxbought = {}
final_list = []

for i in range(0, combination):
    for j in  itertools.combinations(ingredients_names, i):
        final_list = j
        maxbought.update({final_list: boughtno()})
 

names = []
names = ingredients_names.copy()
for i in range(1, len(names)+1):
    temp = []
    for j in  itertools.combinations(names, i):
        final_list = j
        maxbought.update({final_list: boughtno()})
    temp = max(maxbought.values())

names = []
for i in range(len(ingredients_names)):
    final_list = ingredients_names[i]
    maxbought.update({final_list: boughtno()})

maxi = max(maxbought.values())
for key,value in maxbought.items():
    if value == maxi:
        final = key
        break

print(f"\n{len(final)} {' '.join(final)}")
