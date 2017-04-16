if ( -f $HOME/.verboselogin ) echo '>>> Starting your local .login <<<'
if ( -f $HOME/.verboselogin ) set echo

#   Your choice of commands could go here.  Unlike your .cshrc file,
#   which gets invoked every time you start csh or tcsh, this .login
#   file gets invoked only when you're logging in.

if ( -f $HOME/.verboselogin ) unset echo
if ( -f $HOME/.verboselogin ) echo '>>> Done with your local .login <<<'
