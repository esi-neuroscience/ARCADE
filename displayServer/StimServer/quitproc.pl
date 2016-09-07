#(c) Tim Zaman 2012
# modified by Jarrod 2014

use warnings;
use strict;
 
use Win32::OLE qw(in);
 
my($process, $task) = @ARGV; #assume two args 
my $exitcode = 0;
 
my $objWMI = Win32::OLE->GetObject('winmgmts://./root/cimv2');
my $procs = $objWMI->InstancesOf('Win32_Process');
 
my @hits;
foreach my $p (in $procs) {
#push @hits => [ $p->Name, $p->ProcessID ]
    if($p->Name eq $process){
        if("kill" eq $task){
            my($pidnow)=int($p->ProcessID);
            my($procnow)=$p->Name;
            #Now we kill the process
            kill 9, $pidnow; #SIGQUIT (quit signal) = 9  
        }
        elsif("isRunning" eq $task){
            $exitcode = 1;
        }
    }
}
exit($exitcode)