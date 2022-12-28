 mutex
        resource_mutex.acquire()

        # Write to the resource
        write_resource(resource)

        # Release the resource mutex
        resource_mutex.release()