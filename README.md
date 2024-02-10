# ComplexNumbersLibrary

## Table of Contents
1. [Summary](#summary)
2. [Directory Layout (PFL)](#layout)
3. [Implementation](#implementation)
   1. [Methods](#methods)

## Summary <a name="summary"></a>
**ComplexNumbersLibrary** provides a way to implement the mathematical concept of a complex number $x = a + jb$ *(also referred to as the cartesian representation of a complex number)* where $a$ is the real and $b$ the imaginary part.
It also supports the polar form of the complex number $x = r/_d$ where $r$ is the radius length and $d$ the degrees of the angle of the complex number in polar coordinates.

## Directory Layout (PFL) <a name="layout"></a>
The directory layout follows the *PFL* or *Pitchfork layout* method as desrcibed [here](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)

## Implementation <a name="implementation"></a>

>The library currently uses double as its go to type.

### Methods <a name="methods"></a>
```
+ Addition Operator Overloading.
+ Deduction Operator Overloading.
+ Multiplication Operator Overloading.
+ Multiplication Operator Overloading for double.
+ Division Operator Overloading.
+ Calculates the conjugate.
+ Get the Real object.
```
