# Algorithm

```
// identify objects linked together in each group
LOOP over objecs
  set code to A if in group 1
  set code to B if ion group 2

// idebtify objects linked between groups
LOOP over links
   LOOP over group 1 objects
      IF object in first part of link
          add A to code
      ELSE
          add B to code
   LOOP over group 2 objects
      IF object in second part of link
          add A to code
      ELSE
          add C to code

// ensure codes are unique
LOOP over objects in group 1
     add permutation of ABC to code
LOOP over objects in group 2
     add permutation of ABC to code
```

     
  
