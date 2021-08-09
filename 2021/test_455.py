import os
from subprocess import Popen, PIPE
def module_test(filename, right_answer):
    p = Popen(['python', '455.py'], stdout=PIPE, stdin=PIPE, stderr=PIPE)
    f = open(filename, 'rb')
    stdout_data = p.communicate(input=f.read())[0]
    Ls = stdout_data.decode('ascii').split(os.linesep)
    Ls.pop()
    assert Ls == right_answer

module_test('455_input_1.txt', ['3 3', '3 4'])
module_test('455_input_2.txt', ['3 3'])
module_test('455_input_3.txt', ['1 3', '1 4'])
module_test('455_input_4.txt', ['3 1'])
module_test('455_input_5.txt', ['2 5', '3 5'])
module_test('455_input_6.txt', ['5 3', '5 4'])
module_test('455_input_7.txt', ['1 1'])