"""
Provide a comment after each right curly bracket.
This rule only recognizes single line type comments. 

== Violation ==

    } <== Violation. No comment

== Good ==

    }  // if  <== OK.  Comment of bracket 
"""
from nsiqcppstyle_rulehelper import  *
from nsiqcppstyle_reporter import *
from nsiqcppstyle_rulemanager import *

def RunRule(lexer, line, lineno) :
     if Match("^ *};* *$", line) :
         nsiqcppstyle_reporter.Error(DummyToken(lexer.filename, line, lineno, 0), __name__, 'Right curly brackets must be commented.')

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
