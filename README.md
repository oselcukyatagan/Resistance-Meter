# Resistance-Meter

I bought some circuit elements that included some resistors for university work. On my way home the resistors got unsorted. To make it easier to sort them, I made a simple Arduino project.

The circuit works with a simple voltage divider logic.


 ![Scheme-it-export-New-Project-2024-03-02-00-34](https://github.com/oselcukyatagan/Resistance-Meter/assets/115888665/cb825618-58dd-4aa3-8bae-97668121164c)



                                            Figure 1: Voltage divider circuit.
                                           

The voltage drop from the first resistor is inversely-proportional to the resistor connected serially to it. The voltage across the R resistor can be calculated with equation 1.

$\frac{R}{R+10^3}*5V= Vmeasured$                            (1) 

The equation 1 yields,

$\frac{10^3.Vmeasured}{5-Vmeasured}= R$                               (2)
                                             
Derived equation 2 is the logic behind the code that’s calculating the resistance.

![circuit(2)](https://github.com/oselcukyatagan/Resistance-Meter/assets/115888665/25b9817d-5ce4-47a3-a244-73ac64437f60)


                                            Figure 2: Complete circuit diagram of the project. 
