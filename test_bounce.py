import subprocess

def test_output():
    reference_output = open('bounce_reference_output.txt', 'tr').read()
    status, output = subprocess.getstatusoutput('./bounce > output.txt')
    print("output = {}".format(output))
    assert status == 0


    status, diff_output = subprocess.getstatusoutput('diff output.txt bounce_reference_output.txt')
    assert diff_output == ""

    
    
