print "Starting with pandas."
from pandas import Series, DataFrame
import pandas as pd
import numpy as np

obj = Series([4, 7, -5, 3])
print obj
print obj.values
print obj.index

obj2 = Series([4, 7, -5, 3], index=['d','b', 'a', 'c'])
print obj2
print obj2.index
print obj2['a']
obj2['d'] = 6
print obj2
print obj2[['c', 'a', 'd']]

print obj2[obj2>0]
print obj2 * 2
print np.exp(obj2)
print 'b' in obj2
print 'e' in obj2

sdata = {'Ohio': 35000, 'Texas': 71000,  'Oregon': 16000, 'Utah': 5000}

obj3 = Series(sdata)
print obj3

states = ['California', 'Ohio', 'Oregon', 'Texas']
obj4 = Series(sdata, index=states)
print obj4

print pd.isnull(obj4)
print pd.notnull(obj4)
print obj4.isnull()

obj_merge = obj3 + obj4
print obj_merge

obj4.name = 'population'
obj4.index.name = 'state'
print obj4
obj.index = ['Bob', 'Steve', 'Jeff', 'Ryan']
print obj

#Use of datframe
data = {'state':['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada'],
        'year':[2000, 2001, 2002, 2001, 2002],
        'pop':[1.5, 1.7, 3.6, 2.4, 2.9]}

frame = DataFrame(data)
print frame
#Specify the column order
print DataFrame(data, columns=['year', 'state', 'pop'])

frame2 = DataFrame(data, columns=['year', 'state', 'pop', 'debt'], index= ['one', 'two', 'three', 'four', 'five'])
print frame2
print frame2.columns
print frame2['state']
print frame2.year
print frame2.ix['one']
frame2['debt'] = 16.5
frame2['debt'] = np.arange(5.)
print frame

val = Series([-1.2, -1.5, -1.7], index = ['two', 'four', 'five'])
frame2['debt'] = val
print frame2

frame2['eastern'] = frame2.state == 'Ohio'
print frame2

del frame2['eastern']
print frame2.columns

pop = {'Nevada': {2001: 2.4, 2002: 2.9},
       'Ohio': {2000: 1.5, 2002: 3.6}}
frame3 = DataFrame(pop)
print frame3
print frame3.T

# Index objects
obj = Series(range(3), index=['a', 'b', 'c'])
index = obj.index
print index
print index[1:]
# index[1] = 'd' #Indexy nemuzou by prepsany.
index = pd.Index(np.arange(3))

#Reindexing
obj = Series([4.5, 7.2, -5.3, 3.6], index = ['d', 'b', 'a', 'c'])
print obj

obj2 = obj.reindex(['a', 'b', 'c', 'd', 'e'])
print obj2
obj2 = obj.reindex(['a', 'b', 'c', 'd', 'e'], fill_value=0)
print obj

obj3 =Series(['blue', 'purple', 'yellow'], index = [0, 2, 4])
print obj3.reindex(range(6), method='ffill')

frame = DataFrame(np.arange(12).reshape((3,4)), index = ['a', 'c', 'd'],
                   columns=['Ohio', 'Texas', 'California', 'Utah'])
print frame
frame2 = frame.reindex(['a', 'b', 'c', 'd'])
print frame2
states = ['Texas', 'Utah', 'California']
print frame2.reindex(columns = states)
# print frame.reindex(index=['a', 'b', 'c', 'd'], method='ffill', columns=states)
print frame2.ix[['a', 'b', 'c', 'd'], states]

# Dropping entries from an axis
obj = Series(np.arange(5.), index=['a', 'b', 'c', 'd', 'e'])
obj2 = obj.drop(['c', 'd'])
print obj2

data = DataFrame(np.arange(16).reshape((4, 4)), index=['Ohio', 'Colorado', 'Utah', 'New York'],
                 columns=['one', 'two', 'three', 'four'])
print data
print data.drop(['Colorado', 'Ohio'])
print data.drop('two', axis=1)
print data.drop(['two', 'four'], axis=1)


#Selecting and filtering
obj = Series(np.arange(4.), index=['a', 'b', 'c', 'd'])
print obj['b']
print obj[1]
print obj[2:4]
print obj[['b', 'a', 'd']]
print obj[[1, 3]]
print obj[obj < 2]
print obj['b':'c']
obj['b':'c'] = 5
print obj

# Arithmetic and aligment
s1 = Series([7.3, -2.5, 3.4, 1.5], index=['a', 'c', 'd', 'e'])
s2 = Series([-2.1, 3.6, -1.5, 4, 3.1], index=['a', 'c', 'e', 'f', 'g'])

print s1 + s2

#Function application and mapping
frame = DataFrame(np.random.randn(4, 3), columns=list('bde'),
                  index=['Utah', 'Ohio', 'Texas', 'Oregon'])
print frame

f = lambda x: x.max() - x.min()
print frame.apply(f, axis=0)
print frame.apply(f, axis=1)

def f(x):
    return Series([x.min(), x.max()], index=['Min', 'Max'])
print frame.apply(f)

#For dataframe, applymap must be used. For Vector, we can use just map.
format = lambda x: '%.2f' % x # Zaokrouhlit na 2 des. cisla
print frame.applymap(format)
print frame['e'].map(format)

obj = Series(range(4), index=['d', 'a', 'b', 'c'])
print obj.sort_index()

#Ranking
obj = Series([7, -5, 7, 4, 2, 0, 4])
print obj
print obj.rank()
print obj.rank(method='first')

print "Descriptive statistics"
# Descriptive statistics
df = DataFrame([[1.4, np.nan], [7.1, -4.5],
               [np.nan, np.nan], [0.75, -1.3]], index=['a', 'b', 'c', 'd'], columns=['one', 'two'])

print df
print df.sum()
print df.sum(axis = 1)
print df.cumsum()
print df.describe()


print "Correlation and Covariance"
import pandas_datareader.data as web
all_data = {}
for ticker in ['AAPL', 'IBM', 'MSFT', 'GOOG']:
    all_data[ticker] = web.get_data_yahoo(ticker, '1/1/2000', '1/1/2010')

price = DataFrame({tic: data['Adj Close']
                   for tic, data in all_data.iteritems()})
volume = DataFrame({tic: data['Volume']
                    for tic, data in all_data.iteritems()})
returns = price.pct_change()
print returns.tail()
print returns.MSFT.corr(returns.IBM)
print returns.MSFT.cov(returns.IBM)
print returns.corr()
print returns.cov()
print returns.corrwith(returns.IBM)
print returns.corrwith(volume)

obj = Series(['c', 'a', 'd', 'a', 'a', 'b', 'b', 'c', 'c'])
print obj.unique()
print obj.value_counts()
print pd.value_counts(obj.values, sort = False)

mask = obj.isin(['b', 'c'])
print mask
print obj[mask]

data = Series(np.random.randn(10),
              index=[['a', 'a', 'a', 'b', 'b', 'b', 'c', 'c', 'd', 'd'],
                     [1, 2, 3, 1, 2, 3, 1, 2, 2, 3]])
print data.index
print data.unstack()
print data.unstack().stack()

print "Merging others"
left1 = DataFrame({'key': ['a', 'b', 'a', 'a', 'b', 'c'], 'value': range(6)})
right1 = DataFrame({'group_val': [3.5, 7]}, index=['a', 'b'])

print pd.merge(left1, right1, left_on='key', right_index=True)

print " **** ***** DONE ***** ****"