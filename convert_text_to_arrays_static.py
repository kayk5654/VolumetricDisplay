#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
This script generates a data set for a prototype of volumetric display
with 8x8 LED matrix.
It converts text to arduino-compatible format.
"""
import pandas

#Name of files
inputFileName = 'sample static data 03.txt'
outputFileName = 'sample for arduino 03.txt'

#load text file generated from Houdini's geometry spreadsheet
inputFile = pandas.read_csv(inputFileName, sep = "\n")

#convert text to arrays
slice =int(len(inputFile.iloc[:,0]) / 64)

"""
volume = []
for j in range(slice):
    column = []
    for h in range(8):
        row = []
        for i in range(8):      
            row.append(inputFile.iloc[i + h*8 + j*64, 0])
        column.append(row)
    volume.append(column)
print(volume)
"""

outputFile = open(outputFileName,'w')
outputFile.write("{")
for k in range(slice):
    outputFile.write("{")
    
    for l in range(8):
        outputFile.write("{")
        
        for m in range(8):
            outputFile.write(str(int(inputFile.iloc[m + l*8 + k*64, 0])))
            if m < 7:
                outputFile.write(", ")
                
        outputFile.write("}")
        if l < 7:
            outputFile.write(",")
            outputFile.write("\n")
        else:
            outputFile.write("}")
    if k < slice-1:
        outputFile.write(",")
        outputFile.write("\n")
            
outputFile.write("};")
outputFile.close()

print("*** The data set for arduino is ready! ***")
