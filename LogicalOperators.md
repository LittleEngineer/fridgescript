# Introduction #

Logical operators consider zero to mean false and non-zero to mean true. They come in two varieties, comparison and boolean operators.


# Comparison operators #

FridgeScript supports the following C++ like comparison operators. They return zero or non-zero (as opposed to any fixed value equating to true):
  * == equal to
  * != not equal to
  * > greater than
  * < less than
  * >= greater than or equal to
  * <= less than or equal to

# Boolean operators #

FridgeScript supports the following C++ like boolean operators. They return zero or non-zero (as opposed to any fixed value equating to true):
  * ! boolean not
  * && boolean and
  * || boolean or
  * ^^ boolean xor (not fully implemented)