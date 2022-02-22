with open('inputs/e_elaborate.in.txt', 'r') as file:
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

dictionary = dict([(x,0) for x in ingredients_names])

i=1
while i<=n:
    if(i%2==1):
        dat = data[i].split(' ')
        for j in dat:
            if(j in ingredients_names):
                dictionary[j]+=1

    elif (i%2==0):
        dat = data[i].split(' ')
        for j in dat:
            if(j in ingredients_names):
                dictionary[j]-=1

    i+=1

final_list = [x for x in dictionary if dictionary[x]>=0]

print(f"\n{len(final_list)} {' '.join(final_list)}")