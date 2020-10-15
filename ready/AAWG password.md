
AADS: how to reset AADS or AAWG CLI password or local admin
https://kb.avaya.com/kb/index?page=content&id=SOLN334825





In AADS 8.0.1.0.1026 and AAWG 3.8.0.0.361, 3.8 SP1, 
a new feature was introduced to improve the security of the operating system by requiring the lockout of accounts after their password has expired. In environments with strict password expiry and account lockout policies, it is required to immediately lockout accounts that have an expired password. 

Such a strict policy should not be enabled by default because an alternate mechanism must be in place to allow access to the system to unlock locked accounts (e.g.EASG). 





Resolution

The problem will be resolved in the next release of AADS/AAWG. For systems that may be impacted by this issue imminently, please follow the procedure in the Workaround or alternative remediation section to disable the automatic account lockout for the administrative user.


























