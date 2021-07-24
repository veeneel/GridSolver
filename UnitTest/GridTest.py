from pathlib import Path
import PyModule

#data_folder = Path('../../UnitTest')
data_folder = Path('.')

short_list = [
    'Data4x4.txt'
]

long_list = [
    'Data4x4.txt',
    'Data4x4b.txt',
    'Data5x5.txt',
    'Data5x5b.txt',
    'Data3x3_short.txt',
    'Data3x3_long.txt'
]

def main():
    for file in short_list:
        print('--------------------------------------')
        f = data_folder/file
        print(f.name)
        grid = PyModule.PyGrid(str(f))
        print('Valid Data? {}'.format(grid.validity()))
        if grid.validity():
            print('angle of rotation of {} is {:3.1f}\u00b0.'.format(f.name, grid.angle()))
            print('Verify angle? {}'.format(grid.verify()))
            print('Offsets: (xOff = {:.2f}, yOff = {:.2f})'.format(grid.xOffset(), grid.yOffset()))
            grid.save()
        else:
            print('Error Message: {}'.format(grid.errorstr()))
        print('--------------------------------------')

if __name__ == '__main__':
    main()

