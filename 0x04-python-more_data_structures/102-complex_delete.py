#!/usr/bin/python3
def complex_delete(a_dictionary, value):
    key_2_del = [key for key, val in a_dictionary.items() if val == value]
    for key in key_2_del:
        del a_dictionary[key]
    return a_dictionary
