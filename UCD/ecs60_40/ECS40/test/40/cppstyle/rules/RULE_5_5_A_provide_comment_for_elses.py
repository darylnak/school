"""
Provide a comment after each else.
This rule only recognizes single line type comments. 

== Violation ==

    else  <== Violation. No comment

== Good ==

    else  // numbers greater than zero.  <== OK.  Comment of what is true for else
"""
from nsiqcppstyle_rulehelper import  *
from nsiqcppstyle_reporter import *
from nsiqcppstyle_rulemanager import *

def RunRule(lexer, line, lineno) :
     if Match("^ *else", line) and not "//" in line :
         nsiqcppstyle_reporter.Error(DummyToken(lexer.filename, line, lineno, 0), __name__, 'Elses must must be commented.')

ruleManager.AddLineRule(RunRule)



###########################################################################################
# Unit Test
###########################################################################################

from nsiqunittest.nsiqcppstyle_unittestbase import *
class testRule(nct):
    def setUpRule(self):
        ruleManager.AddLineRule(RunRule)
    def test1(self):
        self.Analyze("test/thisFile.c", 
"""
void function(int k, int j, int pp)
{
%s
}
""" % ("d"*121))
        assert CheckErrorContent(__name__)    
    def test2(self):
        self.Analyze("test/thisFile.c", 
"""
void function(int k, int j, int pp)
{
%s
%s
}  // function
""" % ("d"*119, " "*130))
        assert not CheckErrorContent(__name__)    
