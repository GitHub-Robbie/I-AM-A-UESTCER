#!/usr/bin/env python
# coding: utf-8

# In[1]:


# encoding: utf-8
import numpy as np
import matplotlib.pyplot as plt
import pickle
import gzip

f = gzip.open('mnist.pkl.gz', 'rb')   
training_data, validation_data, test_data = pickle.load(f,encoding='bytes')
f.close()


# In[2]:


training_data[0].shape


# In[3]:


training_data[1].shape


# In[2]:


X_train=training_data[0]
y_train=training_data[1]


# In[4]:


from sklearn.model_selection import GridSearchCV
from sklearn import svm
import time


# In[ ]:


param_grid = {'C': [1e-3, 1e-2, 1e-1, 1, 10, 100, 1000], 'gamma': [0.001, 0.0001]}
grid_search = GridSearchCV(model, param_grid, n_jobs = -1, verbose=1)
grid_search.fit(X_train,y_train)
best_parameters = grid_search.best_estimator_.get_params()
for para, val in list(best_parameters.items()):
    print(para, val)
model = SVC(kernel='rbf', C=best_parameters['C'], gamma=best_parameters['gamma'], probability=True)
model.fit(X_train,y_train)


# In[17]:


print (time.strftime('%Y-%m-%d %H:%M:%S'))
model =svm.SVC(C=100.0, kernel='rbf', gamma=0.03)
model.fit(X_train,y_train)
print (time.strftime('%Y-%m-%d %H:%M:%S'))


# In[18]:


X_test=test_data[0]
y_test=test_data[1]
predictions = [int(a) for a in model.predict(X_test)]
num_correct = sum(int(a == y) for a, y in zip(predictions, y_test))
print ("%s of %s test values correct." % (num_correct, len(y_test)))

