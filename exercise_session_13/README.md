# Exercise sheet 13 Arsenije Koljancic

## On Eiger
- Run the "script_py.sh" which run took all csv files "*.csv" and let them run through the mapper and reducer functions. They are saved in the results.txt file 

## On hadoop
        Map-Reduce Framework
                Map input records=35371
                Map output records=538568
                Map output bytes=4472896
                Map output materialized bytes=5550076
                Input split bytes=819
                Combine input records=0
                Combine output records=0
                Reduce input groups=47090
                Reduce shuffle bytes=5550076
                Reduce input records=538568
                Reduce output records=47090
                Spilled Records=1077136
                Shuffled Maps =7
                Failed Shuffles=0
                Merged Map outputs=7
                GC time elapsed (ms)=511
                CPU time spent (ms)=8370
                Physical memory (bytes) snapshot=2050097152
                Virtual memory (bytes) snapshot=21895471104
                Total committed heap usage (bytes)=1882193920
                Peak Map Physical memory (bytes)=269115392
                Peak Map Virtual memory (bytes)=2740215808
                Peak Reduce Physical memory (bytes)=217415680
                Peak Reduce Virtual memory (bytes)=2743562240
        Shuffle Errors
                BAD_ID=0
                CONNECTION=0
                IO_ERROR=0
                WRONG_LENGTH=0
                WRONG_MAP=0
                WRONG_REDUCE=0
        File Input Format Counters
                Bytes Read=12913825
        File Output Format Counters
                Bytes Written=642476
- Map  operations/key-value pairs = 538 568, Reduce operations = 47 090, map input records/lines = 35371
- in the output file the files _SUCCESS and part-00000 were created. The separated and counted words are in part-00000
