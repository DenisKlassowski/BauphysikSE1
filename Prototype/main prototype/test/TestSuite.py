import unittest
import datetime


class TestSuite():

    def allTests(self):
        testmodules = [
            'TestScript_021',
            'TestScript_022',
            'TestScript_023',
            'TestScript_024',
            'TestScript_025',
            'TestScript_026',
            'TestScript_027',
            'TestScript_028',
            'TestScript_029',
            'TestScript_030',
            'TestScript_031',
            'TestScript_032',
            'TestScript_033'
        ]
        suite = unittest.TestSuite()
        for t in testmodules:
            print("... adding:",t)
            suite.addTest(unittest.defaultTestLoader.loadTestsFromName(t))

        print(datetime.datetime.now(),"  test suite started")
        unittest.TextTestRunner().run(suite)


if __name__ == '__main__':
    start = TestSuite()
    start.allTests()