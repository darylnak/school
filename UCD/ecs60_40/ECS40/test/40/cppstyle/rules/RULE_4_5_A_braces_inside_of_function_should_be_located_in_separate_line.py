"""
Braces inside of function definitions should be located in a separate line.

== Violation == 

    void A() { <== Don't Care
        for (;;) { <== ERROR
        }
    }
    class K() 
    { <== Don't Care
        if (true) { <== ERROR
        }
    }

== Good ==


    void A() { <== Don't Care
        for (;;) 
        { <== OK 
        }
    }
    class K() 
    { <== Don't Care
        if (true) 
        { <== OK 
        }
    }

"""
from nsiqcppstyle_rulehelper import  *
from nsiqcppstyle_reporter import *
from nsiqcppstyle_rulemanager import *

def RunRule(lexer, contextStack) :

    t = lexer.GetCurToken()
    if t.type == "LBRACE" :
        t2 = lexer.GetNextMatchingToken(True)
        if t2 != None and t.lineno != t2.lineno : 
            prevToken = lexer.GetPrevTokenSkipWhiteSpaceAndCommentAndPreprocess()
            if prevToken != None and prevToken.type != "EQUALS" and prevToken.lineno == t.lineno and contextStack.Peek().type == "BRACEBLOCK":
                nsiqcppstyle_reporter.Error(t, __name__, "Braces inside of function should be located in separate line.")

ruleManager.AddFunctionScopeRule(RunRule)

###########################################################################################
# Unit Test
###########################################################################################

from nsiqunittest.nsiqcppstyle_unittestbase import *

class testRule(nct):
    def setUpRule(self):
        ruleManager.AddFunctionScopeRule(RunRule)   
    def test1(self):
        self.Analyze("thisfile.c","""
void function() {
    for (;;) 
    {
    }
}
""")
        assert CheckErrorContent(__name__)
    def test2(self):
        self.Analyze("thisfile.c","""
void function() {
    a = 
    {
    }
}
""")
        assert CheckErrorContent(__name__)
    def test3(self):
        self.Analyze("thisfile.c","""
void function() {
    a = {
    }
    while(True) {
    }
    k = {}
}
""")
        assert not CheckErrorContent(__name__)
    
