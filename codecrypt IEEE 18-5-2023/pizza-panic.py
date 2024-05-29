dictionary = {'Anchovies':50,
              'Artichoke': 60,
              'Bacon':92,
              'Broccoli':24,
              'Cheese':80,
              'Chicken':30,
              'Feta':99,
              'Garlic':8,
              'Ham':46,
              'Jalapeno':5,
              'Meatballs':120,
              'Mushrooms':11,
              'Olives':25,
              'Onions':11,
              'Pepperoni':80,
              'Peppers':6,
              'Pineapple':21,
              'Ricotta':108,
              'Sausage':115,
              'Spinach':18,
              'Tomatoes':14}
input_values = input().split()
n = int(input_values[0])
counter = 0
for i in range(1,2*n+1,2):
    combo_length = int(input_values[i])
    toppings = input_values[i+1].split(',')
    counter += combo_length*270
    for item in toppings:
        counter += combo_length*dictionary[item]
print(f"The total calorie intake is {counter}")
