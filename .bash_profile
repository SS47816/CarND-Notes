
# Setting PATH for Python 3.5
# The original version is saved in .bash_profile.pysave
PATH="/Library/Frameworks/Python.framework/Versions/3.5/bin:${PATH}"
export PATH
# added by Miniconda3 4.5.12 installer
# >>> conda init >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$(CONDA_REPORT_ERRORS=false '/Users/SS/miniconda3/bin/conda' shell.bash hook 2> /dev/null)"
if [ $? -eq 0 ]; then
    \eval "$__conda_setup"
else
    if [ -f "/Users/SS/miniconda3/etc/profile.d/conda.sh" ]; then
        . "/Users/SS/miniconda3/etc/profile.d/conda.sh"
        CONDA_CHANGEPS1=false conda activate base
    else
        \export PATH="/Users/SS/miniconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda init <<<

# Sublime Text
# Enable `subl`
export PATH=$PATH:/Applications/Sublime\ Text.app/Contents/SharedSupport/bin/

# Git Workspace
# Enable tab completion
source ~/git-completion.bash

# colors!
green="\[\033[0;32m\]"
blue="\[\033[0;34m\]"
purple="\[\033[0;35m\]"
reset="\[\033[0m\]"

# more colors!
red="\[\033[0;31m\]"
yello="\[\033[0;33m\]"
cyan="\[\033[0;36m\]"
light_red="\[\033[0;91m\]"
light_green="\[\033[0;92m\]"
light_yello="\[\033[0;93m\]"
light_blue="\[\033[0;94m\]"	# purple
light_purple="\[\033[0;95m\]" # pink
light_cyan="\[\033[0;96m\]" # blue
white="\[\033[0;97m\]"

# Change command prompt
source ~/git-prompt.sh
export GIT_PS1_SHOWDIRTYSTATE=1
# '\u' adds the name of the current user to the prompt
# '\$(__git_ps1)' adds git-related stuff
# '\W' adds the name of the current directory
#export PS1="$purple\u$green\$(__git_ps1)$blue \W $ $reset"
export PS1="$light_cyan\u$light_green\$(__git_ps1)$light_yello \W $ $reset"

#Start Sublime from the terminal
alias subl="/Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl"

# Short-cuts
conda activate py3
# cd ~/OneDrive\ -\ National\ University\ of\ Singapore/Autonumous\ Vehicle/Udacity/Self-Driving\ Car\ Engineer/



