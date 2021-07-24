import unittest
from pathlib import Path
import PyModule

data_folder = Path('../../UnitTest')

file_list = [
    'Data4x4.txt',
    'Data4x4b.txt',
    'Data5x5.txt',
    'Data5x5b.txt'
]

class TestGrid(unittest.TestCase):

    def test_rotation(self):
        for file in file_list:
            f = data_folder/file
            grid = PyModule.PyGrid(str(f))
            print('angle of rotation of {} is {:3.1f}\u00b0.'.format(f.name, grid.angle()))
            self.assertEqual(grid.verify(), True)

if __name__ == '__main__':
    unittest.main()