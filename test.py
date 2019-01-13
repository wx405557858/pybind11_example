import example
m = example.ExampleClass()


# get_x
print(m.getx())

# readwrite x
m.x = 2
print(m.x)

# test_tuple
print(m.test_tuple())

# test_vector
print(m.test_vector([1., 2.]))

# test_vector2d
print(m.test_vector2d([[1., 2.], [3., 4.], [5., 6.]]))

# test reference
A = [1., 2., 3.]
m.test_reference(A)
print(A)