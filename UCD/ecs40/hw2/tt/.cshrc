if ( -f $HOME/.verboselogin ) echo '>>> Starting your local .cshrc <<<'
if ( -f $HOME/.verboselogin ) set echo

#   It would not be wise to completely override your existing
#   default $PATH value; here is how a user might add, say, two
#   additional directories to his or her executable $PATH.
#   Uncomment the following line and season to taste.
# set path=( $path $HOME/bin /altpkg/java/bin )

#   On the other hand, a $BROWSER is perhaps less critical and
#   more a matter of individual taste, e.g.:
# setenv BROWSER less

if ( -f $HOME/.verboselogin ) unset echo
if ( -f $HOME/.verboselogin ) echo '>>> Done with your local .cshrc <<<'
