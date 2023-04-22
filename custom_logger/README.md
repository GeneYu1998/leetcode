## CUSTOM LOGGER
cxx custom logger enabling format printing directly on terminals.

<details open="open">
  <summary>__Table of Contents__</summary>
  <ol>
    <li>
      <a href="#build/rebuild">Compiling</a>
    </li>
    <li>
      <a href="#test/run">Run</a>
    </li>
    <li>
      <a href="#clean CMakeCache/output">Clean</a>
    </li>
  </ol>
</details>

### build/rebuild
```bash
    sh build.sh
```

### test/run
after build, you should find an exectable called `output` at source root dir.
you could directly run it:
```bash
    ./output
```
<br />
<p align="center">
  <a href="">
    <img src="pics\no_arguments.jpg">
  </a>
</p>

or put some extra arguments:
```bash
    ./output imperial huawei bilibili geneyu123
```
<p align="center">
  <a href="">
    <img src="pics\with_arguments.jpg">
  </a>
</p>

### clean CMakeCache/output
```bash
    sh clean.sh
```
