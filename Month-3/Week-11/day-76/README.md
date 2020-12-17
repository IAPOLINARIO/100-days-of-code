## The Cake Thief

You are a renowned thief who has recently switched from stealing precious metals to stealing cakes because of the insane profit margins. You end up hitting the jackpot, breaking into the world's largest privately owned stock of cakes—the vault of the Queen of England.
While Queen Elizabeth has a limited number of types of cake, she has an unlimited supply of each type.
Each type of cake has a weight and a value, stored in a tuple with two indices:

- An integer representing the **weight** of the cake in kilograms
- An integer representing the **monetary value** of the cake in British shillings

For example:

```
// weighs 7 kilograms and has a value of 160 shillings
CakeType cakeType = {7, 160};

// weighs 3 kilograms and has a value of 90 shillings
CakeType cakeType = {3, 90};
```

You brought a duffel bag that can hold limited weight, and you want to make off with the most valuable haul possible.

Write a function `maxDuffelBagValue()` that takes **an array of cake type structures** and a **weight capacity**, and returns **the maximum monetary value the duffel bag can hold**.

For example:

```
cakes       = [(7, 160), (3, 90), (2, 15)]
capacity    = 20


max_duffel_bag_value(cake_tuples, capacity)
# Returns 555 (6 of the middle type of cake and 1 of the last type of cake)
```
