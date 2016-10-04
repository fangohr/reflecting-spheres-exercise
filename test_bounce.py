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
        
    
