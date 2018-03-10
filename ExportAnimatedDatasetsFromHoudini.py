node = hou.pwd()
geo = node.geometry()

# define file name. not only .txt
fileName = "datasets_animate_test02.txt"

# set length of animation in frame number
endFrame = 900

# get the number of slices
slice = hou.evalParm("../ncy")

# rounding each elements of color
# swap index of red and green
def roundColor(color):
    r = int(round(color[0]*255))
    g = int(round(color[1]*255))
    b = int(round(color[2]*255))
    roundedColor = (r, g, b)
    return roundedColor

# swap index of red and green
def roundColorGRB(color):
    r = int(round(color[0]*255))
    g = int(round(color[1]*255))
    b = int(round(color[2]*255))
    roundedColor = (g, r, b)
    return roundedColor

def roundColorAdjustedGRB(color):
    r = int(round(color[0]*255*0.066))
    g = int(round(color[1]*255*0.216))
    b = int(round(color[2]*255))
    roundedColor = (g, r, b)
    return roundedColor

# get current frame number
currentFrame = hou.frame()

# write a file
if currentFrame == 1:


    # write datasets
    file = open(fileName, "w")
    #start of animation
    file.write("{")
    #start of frame
    file.write("{")
    for i in range(geo.countPrimType("Poly")):
        color = geo.iterPrims()[i].attribValue("Cd")
        #roundedColor = roundColorGRB(color)
        roundedColor = roundColorAdjustedGRB(color)
        file.write("".join(str('#%02x%02x%02x' % roundedColor)).replace("#", "0x"))
        if i < geo.countPrimType("Poly")-1:
            file.write(",")
            file.write("\n")
    #end of frame
    file.write("},")
    file.write("\n")

elif currentFrame == endFrame:
    file = open(fileName, "a")
    #start of frame
    file.write("{")
    for i in range(geo.countPrimType("Poly")):
        color = geo.iterPrims()[i].attribValue("Cd")
        #roundedColor = roundColorGRB(color)
        roundedColor = roundColorAdjustedGRB(color)
        file.write("".join(str('#%02x%02x%02x' % roundedColor)).replace("#", "0x"))
        if i < geo.countPrimType("Poly")-1:
            file.write(",")
            file.write("\n")

    #end of animation
    file.write("}};")

else:
    file = open(fileName, "a")
    #start of frame
    file.write("{")
    for i in range(geo.countPrimType("Poly")):
        color = geo.iterPrims()[i].attribValue("Cd")
        #roundedColor = roundColorGRB(color)
        roundedColor = roundColorAdjustedGRB(color)
        file.write("".join(str('#%02x%02x%02x' % roundedColor)).replace("#", "0x"))
        if i < geo.countPrimType("Poly")-1:
            file.write(",")
            file.write("\n")
    #end of frame
    file.write("},")
    file.write("\n")
file.close()
