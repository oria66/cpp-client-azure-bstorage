#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <was/storage_account.h>
#include <was/blob.h>
//#include <cpprest/filestream.h>
//#include <cpprest/containerstream.h>

//using namespace azure::storage;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Retrieve the connection string for use with the application. The storage
    // connection string is stored in an environment variable on the machine
    // running the application called AZURE_STORAGE_CONNECTION_STRING.
    const char* connectionString = std::getenv("DefaultEndpointsProtocol=https;AccountName=minesstorage;AccountKey=YWosHXBEZLSWjxdEx60XGErG6+id4mOlrAMQ4Smidd2pT51T8gwegi5VwynuASlzF2vdgVyzSufdpaw+PhO7aQ==;EndpointSuffix=core.windows.net");

    try
     {
         // Initialize storage account
         azure::storage::cloud_storage_account storage_account = azure::storage::cloud_storage_account::parse(connectionString);

//         // Create a blob container
//         azure::storage::cloud_blob_client blob_client = storage_account.create_cloud_blob_client();
//         azure::storage::cloud_blob_container container = blob_client.get_container_reference(_XPLATSTR("my-sample-container"));

//         // Return value is true if the container did not exist and was successfully created.
//         container.create_if_not_exists();

//         // Make the blob container publicly accessible
//         azure::storage::blob_container_permissions permissions;
//         permissions.set_public_access(azure::storage::blob_container_public_access_type::blob);
//         container.upload_permissions(permissions);

//         // Upload a blob from a file
//         concurrency::streams::istream input_stream = concurrency::streams::file_stream<uint8_t>::open_istream(_XPLATSTR("DataFile.txt")).get();
//         azure::storage::cloud_block_blob blob1 = container.get_block_blob_reference(_XPLATSTR("my-blob-1"));
//         blob1.upload_from_stream(input_stream);
//         input_stream.close().wait();

//         // Upload some blobs from text
//         azure::storage::cloud_block_blob blob2 = container.get_block_blob_reference(_XPLATSTR("my-blob-2"));
//         blob2.upload_text(_XPLATSTR("more text"));
//         azure::storage::cloud_block_blob blob3 = container.get_block_blob_reference(_XPLATSTR("my-directory/my-sub-directory/my-blob-3"));
//         blob3.upload_text(_XPLATSTR("other text"));

         // List blobs in the blob container
//         azure::storage::continuation_token token;
//         do
//         {
//             azure::storage::list_blob_item_segment result = container.list_blobs_segmented(token);
//             for (auto& item : result.results())
//             {
//                 if (item.is_blob())
//                 {
//                     ucout << _XPLATSTR("Blob: ") << item.as_blob().uri().primary_uri().to_string() << std::endl;
//                 }
//                 else
//                 {
//                     ucout << _XPLATSTR("Directory: ") << item.as_directory().uri().primary_uri().to_string() << std::endl;
//                 }
//             }
//             token = result.continuation_token();
//         }
//         while (!token.empty());

//         // Download a blob to a stream
//         concurrency::streams::container_buffer<std::vector<uint8_t>> buffer;
//         concurrency::streams::ostream output_stream(buffer);
//         azure::storage::cloud_block_blob binary_blob = container.get_block_blob_reference(_XPLATSTR("my-blob-1"));
//         binary_blob.download_to_stream(output_stream);
//         ucout << _XPLATSTR("Stream: ") << utility::string_t(buffer.collection().begin(), buffer.collection().end()) << std::endl;

//         // Download a blob as text
//         azure::storage::cloud_block_blob text_blob = container.get_block_blob_reference(_XPLATSTR("my-blob-2"));
//         utility::string_t text = text_blob.download_text();
//         ucout << _XPLATSTR("Text: ") << text << std::endl;

//         // Delete the blobs
//         blob1.delete_blob();
//         blob2.delete_blob();
//         blob3.delete_blob();

//         // Create an append blob
//         azure::storage::cloud_append_blob append_blob = container.get_append_blob_reference(_XPLATSTR("my-append-1"));
//         append_blob.properties().set_content_type(_XPLATSTR("text/plain; charset=utf-8"));
//         append_blob.create_or_replace();

//         // Append two blocks
//         concurrency::streams::istream append_input_stream1 = concurrency::streams::bytestream::open_istream(utility::conversions::to_utf8string(_XPLATSTR("some text.")));
//         concurrency::streams::istream append_input_stream2 = concurrency::streams::bytestream::open_istream(utility::conversions::to_utf8string(_XPLATSTR("more text.")));
//         append_blob.append_block(append_input_stream1, utility::string_t());
//         append_blob.append_block(append_input_stream2, utility::string_t());
//         append_input_stream1.close().wait();
//         append_input_stream2.close().wait();

//         // Download append blob as text
//         utility::string_t append_text = append_blob.download_text();
//         ucout << _XPLATSTR("Append Text: ") << append_text << std::endl;

//         // Cancellation token
//         pplx::cancellation_token_source source; // This is used to cancel the request.
//         auto download_text_task = append_blob.download_text_async(azure::storage::access_condition(), azure::storage::blob_request_options(), azure::storage::operation_context(), source.get_token());
//         source.cancel();// This call will cancel download_text_task
//         try
//         {
//             auto downloaded_text = download_text_task.get();
//             ucout << _XPLATSTR("Text downloaded successfully unexpectedly, text is: ") << downloaded_text << std::endl;
//         }
//         catch (const azure::storage::storage_exception& e)
//         {
//             ucout << _XPLATSTR("Operation should be cancelled, the error message is: ") << e.what() << std::endl;
//         }

//         // Millisecond level timeout
//         azure::storage::blob_request_options options;
//         options.set_maximum_execution_time(std::chrono::milliseconds(1));
//         try
//         {
//             download_text_task = append_blob.download_text_async(azure::storage::access_condition(), options, azure::storage::operation_context());
//             auto downloaded_text = download_text_task.get();
//             ucout << _XPLATSTR("Text downloaded successfully unexpectedly, text is: ") << downloaded_text << std::endl;
//         }
//         catch (const azure::storage::storage_exception& e)
//         {
//             ucout << _XPLATSTR("Operation should be timed-out, the error message is: ") << e.what() << std::endl;
//         }

//         // Delete the blob
//         append_blob.delete_blob();

//         // Delete the blob container
//         // Return value is true if the container did exist and was successfully deleted.
//         container.delete_container_if_exists();
     }
     catch (const azure::storage::storage_exception& e)
     {
//         ucout << _XPLATSTR("Error: ") << e.what() << std::endl;

//         azure::storage::request_result result = e.result();
//         azure::storage::storage_extended_error extended_error = result.extended_error();
//         if (!extended_error.message().empty())
//         {
//             ucout << extended_error.message() << std::endl;
//         }
     }
     catch (const std::exception& e)
     {
//         ucout << _XPLATSTR("Error: ") << e.what() << std::endl;
     }

    return a.exec();
}
