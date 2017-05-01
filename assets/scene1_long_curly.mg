# This is a comment
# Comments start with '#' character and are stripped away when parsing

# Follow definitions of acceptable objects that can be created - any other string will produce parsing error

# Follows mesh definition
# mesh accepts only the parameters listed below - any other string will produce parsing error
# id should be a positive integer and unique for each mesh defined in the scene file
# id is not the actual id used in the program but is used to link object3D with a mesh
# filename should be a valid file path only obj triangular meshes supported
mesh
id 1
filename assets/medusa1.obj
/mesh

# Follows object3D definition
# object3D accepts only the parameters listed below - any other string will produce parsing error
# id should be a positive integer and unique for each object3D defined in the scene file
# id is not the actual id used in the program but is used to link hair with an object3D
# meshId links object3D with a mesh
# transform is a sequence of 9 values in the form:
# euler_angle_x euler_angle_y, euler_angle_z scale_x scale_y scale_z translate_x translate_y translate_z
# rotation is in xyz order
# transform translates to 4x4 column major matrix placing the object in space
# collisionShape is defined as transform and translates to 4x4 column major matrix
# collisionShape defines an ellipsoid with which hair will collide
# there might be more than one collisionShape defined for the object
object3D
id 1
meshId 1
transform 0 0 0 1 1 1 0 0 0
collisionShape -23.853 0 0 1.967 2.953 2.355 0 2.664 0
/object3D

# Follows hair definition
# hair accepts only the parameters listed below - any other string will produce parsing error
# id should be a positive integer and unique for each hair defined in the scene file
# id is not the actual id used in the program
# objId links hair with an object3D
# type can have the following values curly/straight
# faceCnt defines number of faces to put hair on
# NOTE: faceCnt should precede faceList for hair to be parsed correctly
# faceList contains face indices and can be autogenerated by Maya:
# import the obj file used for the mesh above, select the faces to put hair on and run script from assets/MayaGetSelectedPrimitives.py
# this will output faceCnt faceList, copy-paste here
hair
id 1
objId 1
# AUTO GENERATED BY MAYA
# selected faces:
faceCnt  374
faceList 863 864 867 868 871 872 875 876 879 880 881 882 883 884 885 886 887 890 891 892 893 894 895 896 897 898 899 900 901 902 903 904 905 906 907 908 909 910 911 912 913 914 915 916 917 918 919 920 1128 1208 1209 1210 1211 1212 1213 1214 1215 1216 1217 1222 1223 1336 1337 1338 1339 1340 1341 1342 1343 1344 1345 1346 1347 1348 1349 1350 1351 1352 1353 1354 1355 1356 1357 1358 1359 1360 1361 1362 1363 1364 1365 1366 1367 1368 1369 1370 1371 1372 1373 1374 1375 1376 1377 1378 1379 1380 1381 1382 1383 1384 1385 1386 1387 1388 1389 1390 1391 1392 1393 1394 1395 1396 1397 1398 1399 1400 1401 1402 1403 1404 1405 1406 1407 1408 1409 1410 1411 1412 1413 1414 1415 1416 1417 1418 1419 1420 1421 1422 1423 1424 1425 1476 1477 1478 1479 1480 1481 1482 1483 1484 1485 1486 1487 1488 1489 1490 1491 1492 1493 1496 1497 1937 1938 1939 1940 1941 1942 1947 2347 2350 2351 2352 2353 2354 2355 2356 2375 3336 3337 3340 3341 3344 3345 3348 3349 3352 3353 3354 3355 3356 3357 3358 3359 3361 3362 3364 3365 3366 3367 3368 3369 3370 3371 3372 3373 3374 3375 3376 3377 3378 3379 3380 3381 3382 3383 3384 3385 3386 3387 3388 3389 3390 3391 3392 3393 3598 3680 3681 3682 3683 3684 3685 3686 3687 3688 3689 3690 3691 3804 3805 3806 3807 3808 3809 3810 3811 3812 3813 3814 3815 3816 3817 3818 3819 3820 3821 3822 3823 3824 3825 3826 3827 3828 3829 3830 3831 3832 3833 3834 3835 3836 3837 3838 3839 3840 3841 3842 3843 3844 3845 3846 3847 3848 3849 3850 3851 3852 3853 3854 3855 3856 3857 3858 3859 3860 3861 3862 3863 3864 3865 3866 3867 3868 3869 3870 3871 3872 3873 3874 3875 3876 3877 3878 3879 3880 3881 3882 3883 3884 3885 3886 3887 3888 3889 3890 3891 3892 3893 3954 3955 3956 3957 3958 3959 3960 3961 3962 3963 3964 3965 3966 3967 3968 3969 3970 3971 3972 3973 4407 4408 4409 4412 4413 4415 4788 4792 4794 4795 4796 4797 4798 4799 4820 4821

type curly
length 4.5
lengthVariance 1
helicalRadius 0.3
helicalPitch 0.15
density 0.001
thickness 0.07
nParticles 15

netForce 0 -9.81 0
drag 0.000001

resolveCollisions 1
resolveSelfInteractions 1
selfInteractionDist 0.5
selfStiction 0.3
selfRepulsion 0.000004

pbdIter 10

bendStiffness 0.00005
twistStiffness 0.0001
maxElasticForce 100
minimizationMethod none
minimizationTolerance 0.1
minimizationMaxIter 10

/hair

# use timestep < 0.03s