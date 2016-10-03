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
    reference_output = open('bounce_reference_output.txt', 'tr').readlines()
    status, output = subprocess.getstatusoutput('./bounce > output.txt')
    for ref, cur in zip(reference_output, output.splitlines()):
        assert ref.index('x') == cur.index('x')
    assert status == 0




    
