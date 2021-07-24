import csv
import bisect
# grid size = 4 (min), 100 (max)
squares = [x*x for x in range(2,11)]
#print(squares)

# nextHighest = lambda seq,x: min([(i-x,i) for i in seq if x<=i] or [(0,None)])[1]
# nextLowest  = lambda seq,x: min([(x-i,i) for i in seq if x>=i] or [(0,None)])[1]

def validate(fname):
    print('Input File {} :'.format(fname))
    print('---------------------')
    # Open the input file 
    with open(fname, "r") as gridData:
        #Set up CSV reader and process the header
        csvReader = csv.reader(gridData)
        # Make an empty list
        coordList = []
    
        # Loop through the lines in the file and get each coordinate
        for row in csvReader:
            x = row[0]
            y = row[1]
            coordList.append([x,y])
            #print(x)

        length = len(coordList)
        # print(length)
        if length not in squares:
            print('Incorrect Size: {} points in file.'.format(length))
            index = bisect.bisect(squares, length)
            # print('Smaller than target: {}'.format(squares[index-1]))
            # print('Greater than target: {}'.format(squares[index]))
            diff1 = length - squares[index-1]
            diff2 = squares[index] -length
            if (diff2 < diff1):
                print('Too few points in file')
            else:
                print('Too many points in file')
        else:
            size = squares.index(length)+2
            print('Grid Size: {0}x{0}'.format(size))

        # print('Greater than target: {}'.format(nextHighest(squares,length)))
        # print('Smaller than target: {}'.format(nextLowest(squares,length)))

        # Print the coordinate list
        #print (coordList[0])
        print('---------------------\n')

def main():
    validate('Data4x4.txt')
    validate('Data4x4b.txt')
    validate('Data4x4c.txt')
    validate('Data4x4d.txt')

if __name__ == '__main__':
    main()