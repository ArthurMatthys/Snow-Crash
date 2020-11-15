
int main(int argc,char **argv)

{
  char *__cp;
  uint16_t uVar1;
  int __fd;
  int __fd_00;
  ssize_t sVar2;
  size_t __n;
  int *piVar3;
  char *__file;
  int in_GS_OFFSET;
  char *file;
  char *host;
  int fd;
  int ffd;
  int rc;
  char buffer [4096];
  sockaddr_in sin;
  undefined local_1024 [4096];
  uint local_24;
  in_addr_t local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  
  local_14 = *(int *)(in_GS_OFFSET + 0x14);
  if (argc < 3) {
    printf("%s file host\n\tsends file to host if you have access to it\n",*argv);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  __file = argv[1];
  __cp = argv[2];
  __fd = access(argv[1],4);
  if (__fd == 0) {
    printf("Connecting to %s:6969 .. ",__cp);
    fflush(stdout);
    __fd = socket(2,1,0);
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_24 = 2;
    local_20 = inet_addr(__cp);
    uVar1 = htons(0x1b39);
    local_24 = local_24 & 0xffff | (uint)uVar1 << 0x10;
    __fd_00 = connect(__fd,(sockaddr *)&local_24,0x10);
    if (__fd_00 == -1) {
      printf("Unable to connect to host %s\n",__cp);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    sVar2 = write(__fd,".*( )*.\n",8);
    if (sVar2 == -1) {
      printf("Unable to write banner to host %s\n",__cp);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    printf("Connected!\nSending file .. ");
    fflush(stdout);
    __fd_00 = open(__file,0);
    if (__fd_00 == -1) {
      puts("Damn. Unable to open file");
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    __n = read(__fd_00,local_1024,0x1000);
    if (__n == 0xffffffff) {
      piVar3 = __errno_location();
      __file = strerror(*piVar3);
      printf("Unable to read from file: %s\n",__file);
                    /* WARNING: Subroutine does not return */
      exit(1);
    }
    write(__fd,local_1024,__n);
    __fd = puts("wrote file!");
  }
  else {
    __fd = printf("You don\'t have access to %s\n",__file);
  }
  if (local_14 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return __fd;
}

