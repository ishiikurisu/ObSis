You can use split for this:

``` sh
tar czpvf - /path/to/archive | split -d -b 100M - tardisk
```

This tells tar to send the data to stdout, and split to pick it from stdin - additionally using a numeric suffix (-d), a chunk size (-b) of 100M and using 'disk' as the base for the resulting filenames (tardisk00, tardisk01, etc.).

To extract the data afterwards you can use this:

``` sh
cat tardisk* | tar xzpvf -
```
