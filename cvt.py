#!/usr/bin/env python

input_str = input("list 1d or 2d\n")

output_str =  input_str.replace('[', '{').replace(']', '}')

print(output_str)
