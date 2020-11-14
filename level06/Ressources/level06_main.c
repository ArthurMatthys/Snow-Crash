
undefined4 main(undefined4 param_1,int param_2,char **param_3)

{
  int iVar1;
  char **__envp;
  __gid_t __rgid;
  __uid_t __ruid;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  undefined4 local_24;
  undefined *local_18;
  
  __envp = param_3;
  iVar1 = param_2;
  local_18 = &param_1;
  local_2c = strdup("");
  local_28 = strdup("");
  if (*(int *)(iVar1 + 4) != 0) {
    free(local_2c);
    local_2c = strdup(*(char **)(iVar1 + 4));
    if (*(int *)(iVar1 + 8) != 0) {
      free(local_28);
      local_28 = strdup(*(char **)(iVar1 + 8));
    }
  }
  __rgid = getegid();
  __ruid = geteuid();
  setresgid(__rgid,__rgid,__rgid);
  setresuid(__ruid,__ruid,__ruid);
  local_34 = "/usr/bin/php";
  local_30 = "/home/user/level06/level06.php";
  local_24 = 0;
  execve("/usr/bin/php",&local_34,__envp);
  return 0;
}

