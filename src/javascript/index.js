var apclust = require('./AffinityPropagation_seonu.js')

var array = apclust.getDataArray()
console.log(array)
var result = apclust.getClusters(array, {preference: "median", damping: 0.5, maxIter: 50, convIter: 50})
console.log(result)