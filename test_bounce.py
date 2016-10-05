import subprocess
import pytest


#@pytest.mark.skip
#def test_output():
#    reference_output = open('bounce_reference_output.txt', 'tr').read()
#    status, output = subprocess.getstatusoutput('./bounce > output.txt')
#    print("output = {}".format(output))
#    assert status == 0
#
#
#    status, diff_output = subprocess.getstatusoutput('diff output.txt bounce_reference_output.txt')
#    assert diff_output == ""



def test_output_ignore_whitespace():
    reference_output = open('bounce_reference_output.txt', 'tr')
    status, command_output = subprocess.getstatusoutput('./bounce > output.txt')
    assert status == 0
    print("command_output = '{}'".format(command_output));
    
    for line_nr, (ref, cur) in enumerate(zip(reference_output, open("output.txt", 'rt'))):
        print("processing line {}:".format(line_nr));
        if 'x' in cur:
            assert 'x' in ref
            assert ref.index('x') == cur.index('x')

            
def test_output_2_particles():
    reference_output = open('bounce_reference_output-2.txt', 'tr')
    status, command_output = subprocess.getstatusoutput('./bounce > output.txt')
    print("command_output = '{}'".format(command_output));
    assert status == 0
    for ref, cur in zip(reference_output, open('output.txt', 'tr')):
        if 'x' in ref:
            assert 'x' in cur
            assert ref.index('x') == cur.index('x')
        if '*' in ref:
            assert '*' in cur
            assert ref.index('*') == cur.index('*')
        

def test_output_is_nontrivial():
    status, command_output = subprocess.getstatusoutput('./bounce')
    assert status == 0
    print(len(command_output))
    #
    # assert len(command_output) == 4919   # just assume current number is correct

    # as we add additional outputs, the overall output gets longer
    assert len(command_output) >= 4919   # just assume current number is correct
    
    
    n_x = command_output.count('x')
    print("number of x = {}".format(n_x))
    assert n_x == 59
    n_start = command_output.count('*')
    print("number of * = {}".format(n_start))
    assert n_start ==60

    # x has one fewer, as it is overwritten by particle 2, which has symbol *
    


