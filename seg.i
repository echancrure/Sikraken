typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long unsigned int size_t;
struct _IO_FILE {
  int _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int x;
  int y;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *)];
};

typedef __ssize_t __io_read_fn (int x);